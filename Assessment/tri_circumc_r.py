import random_index_cal
import xlrd
import math
from matplotlib import pyplot

class Groupnum_Tri_circumR:
	def radius_tri(self,sx,sy,sz):
		a = 0.0
		b = 0.0
		c = 0.0
		for i in range(3):
			a += (sx[i]-sy[i])*(sx[i]-sy[i])
			b += (sz[i]-sy[i])*(sz[i]-sy[i])
			c += (sx[i]-sz[i])*(sx[i]-sz[i])
		a = math.sqrt(a)
		b = math.sqrt(b)
		c = math.sqrt(c)
		p = (a+b+c)/2.0
		return 0.25*a*b*c/math.sqrt(p*(p-a)*(p-b)*(p-c))

	def cal_circum_radius(self,sx,sy,sz):
		group_size =len(sx.col_values(0))
		frame_num = len(sx.row_values(0))
		sum_radius = 0.0
		max_radius = 0.0
		
		'''to store the radius of each insect in each frame interval'''
		radius_matrix = [[0.0 for i in range(frame_num-2)] for j in range(group_size)]
		for i in range(group_size):
			for j in range(frame_num-2):
				temp_fir = []
				temp_fir.append(sx.cell_value(i,j))
				temp_fir.append(sx.cell_value(i,j+1))
				temp_fir.append(sx.cell_value(i,j+2))
				temp_sec = []
				temp_sec.append(sy.cell_value(i,j))
				temp_sec.append(sy.cell_value(i,j+1))
				temp_sec.append(sy.cell_value(i,j+2))
				temp_thi = []
				temp_thi.append(sz.cell_value(i,j))
				temp_thi.append(sz.cell_value(i,j+1))
				temp_thi.append(sz.cell_value(i,j+2))
				radius_matrix[i][j] = self.radius_tri(temp_fir,temp_sec,temp_thi)
				max_radius = max(max_radius,radius_matrix[i][j])
				sum_radius += radius_matrix[i][j]

		return group_size,sum_radius/group_size/(frame_num-2),max_radius


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

	for i in range(len(result_matrix)):
		print(result_matrix[i])
