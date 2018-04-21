import random_index_cal
import xlrd
import math
from matplotlib import pyplot
import numpy as np
from scipy.optimize import curve_fit

def func(x,a,b):
	return a*np.log(x/b)

class Groupnum_Tri_circumR:
	def velocity_bar(self,sx,sy,sz):
		vel_fir = 0.0
		vel_sec = 0.0
		for i in range(3):
			vel_fir = vel_fir+(sx[i]-sy[i])*(sx[i]-sy[i])
			vel_sec = vel_sec+(sz[i]-sy[i])*(sz[i]-sy[i])

		return 100*(math.sqrt(vel_fir)+math.sqrt(vel_sec))/2

	def radius_tri(self,sx,sy,sz):
		a = 0.0
		b = 0.0
		c = 0.0
		for i in range(3):
			a = a+(sx[i]-sy[i])*(sx[i]-sy[i])
			b = b+(sz[i]-sy[i])*(sz[i]-sy[i])
			c = c+(sx[i]-sz[i])*(sx[i]-sz[i])

		a = math.sqrt(a)
		b = math.sqrt(b)
		c = math.sqrt(c)
		p = (a+b+c)/2.0
		return 0.25*a*b*c/math.sqrt(p*(p-a)*(p-b)*(p-c))

	def cal_circum_radius(self,sx,sy,sz):
		group_size =len(sx.col_values(0))
		frame_num = len(sx.row_values(0))
		sum_radius = 0.0
		sum_overload = 0.0
		max_radius = 0
		max_overload = 0.0
		
		'''to store the radius of each insect in each frame interval'''
		radius_matrix = [[0.0 for i in range(frame_num-2)] for j in range(group_size)]
		overload_matrix = [[0.0 for i in range(frame_num-2)] for j in range(group_size)]
		for i in range(group_size):
			for j in range(frame_num-2):
				temp_fir = []#the coordinate of the first node
				temp_sec = []
				temp_thi = []
				temp_fir.append(sx.cell_value(i,j)/1000)
				temp_sec.append(sx.cell_value(i,j+1)/1000)
				temp_thi.append(sx.cell_value(i,j+2)/1000)
				temp_fir.append(sy.cell_value(i,j)/1000)
				temp_sec.append(sy.cell_value(i,j+1)/1000)
				temp_thi.append(sy.cell_value(i,j+2)/1000)
				temp_fir.append(sz.cell_value(i,j)/1000)
				temp_sec.append(sz.cell_value(i,j+1)/1000)
				temp_thi.append(sz.cell_value(i,j+2)/1000)

				radius_matrix[i][j] = self.radius_tri(temp_fir,temp_sec,temp_thi)
				max_radius = max(max_radius,radius_matrix[i][j])
				sum_radius = sum_radius+radius_matrix[i][j]

				vel_temp = self.velocity_bar(temp_fir,temp_sec,temp_thi)
				vel_t = vel_temp*vel_temp
				overload_matrix[i][j] = vel_t/radius_matrix[i][j]
				sum_overload = sum_overload+overload_matrix[i][j]
				max_overload = max(max_overload,overload_matrix[i][j])


		return group_size,sum_radius/group_size/(frame_num-2),max_radius,sum_overload/group_size/(frame_num-2),max_overload


if __name__ == '__main__':
	data_sheet = random_index_cal.Data_manipulate(0,0.01,1,0.2,19,0)
	result_matrix = []
	for i in range(1,27):	
		file_path = 'D:\\FDU\\Template\\CS\\数学建模\\轨迹_数量\\'+str(i)+'.xlsx'
		data_X = data_sheet.data_input(file_path,'Sx')
		data_Y = data_sheet.data_input(file_path,'Sy')
		data_Z = data_sheet.data_input(file_path,'Sz')
		data = Groupnum_Tri_circumR()
		R_N_pair = data.cal_circum_radius(data_X,data_Y,data_Z)
		result_matrix.append(R_N_pair)

	Group_n = []
	Max_r = []
	Bar_r = []
	Max_ol = []
	Bar_ol = []
	for i in range(0,26):
		Group_n.append(result_matrix[i][0])
		Max_r.append(result_matrix[i][2])
		Bar_r.append(result_matrix[i][1])
		Max_ol.append(result_matrix[i][4])
		Bar_ol.append(result_matrix[i][3])

	#fit it!
	# z1 = np.polyfit(Group_n,Max_ol,4)
	# p1 = np.poly1d(z1)
	# yvals = p1(Group_n)
	# plot2 = pyplot.plot(Group_n,yvals)
	# pyplot.show()

	popt,pcov = curve_fit(func,Group_n,Max_ol)
	a = popt[0]
	b = popt[1]
	yvals = func(Group_n,a,b)
	plot1 = pyplot.plot(Group_n,yvals)

	# pyplot.scatter(Group_n,Max_r)
	# pyplot.xlabel('group_number')
	# pyplot.ylabel('max_radius')
	# pyplot.title('max_R-group_num curve')
	# pyplot.show()

	# pyplot.scatter(Group_n,Bar_r)
	# pyplot.xlabel('group_number')
	# pyplot.ylabel('mean_radius')
	# pyplot.title('mean_R-group_num curve')
	# pyplot.show()

	plot2 = pyplot.scatter(Group_n,Max_ol)
	pyplot.xlabel('group_number')
	pyplot.ylabel('max_overload')
	pyplot.title('max_overload-group_num curve')
	pyplot.show()

	# pyplot.scatter(Group_n,Bar_ol)
	# pyplot.xlabel('group_number')
	# pyplot.ylabel('mean_overload')
	# pyplot.title('mean_overload-group_num curve')
	# pyplot.show()
