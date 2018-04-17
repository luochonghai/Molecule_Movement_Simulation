#-*- coding=utf-8
import xlrd  
import math
from matplotlib import pyplot

class Data_manipulate:
    def __init__(self,sample_size,interval,K,length_dro,length_box,terminal):
        self.sample_size = sample_size
        self.interval = interval
        self.K = K
        self.length_dro = length_dro
        self.length_box = length_box
        self.terminal = terminal

    def drawCumulativeHist(self,velocity):
        v_length = []
        for i in range(self.sample_size):
            v_length += velocity[i]
        pyplot.hist(v_length,300,normed = True,histtype = 'step',cumulative = True)
        pyplot.xlabel('velocity_length')
        pyplot.ylabel('frequency')
        pyplot.title('_frequency_statistic_plot of v_length')
        pyplot.show()

    def drawHist(self,velocity):
        v_length = []
        for i in range(self.sample_size):
            v_length += velocity[i]
        pyplot.hist(v_length,300)
        pyplot.xlabel('velocity_length')
        pyplot.ylabel('frequency')
        pyplot.title('_frequency_statistic_plot of v_length')
        pyplot.show()

    def data_input(self,file_path,sheet_name):
        workbook = xlrd.open_workbook(file_path)  
        #print(workbook.sheet_names())                  #查看所有sheet  
        #booksheet = workbook.sheet_by_index(0)         #用索引取第一个sheet  
        booksheet = workbook.sheet_by_name(sheet_name)  #或用名称取sheet  
        #读单元格数据  
        cell_11 = booksheet.cell_value(0,0)  
        #cell_21 = booksheet.cell_value(1,0)  
        #读一行数据  
        row_3 = booksheet.row_values(0)
        return booksheet

    #sheetdata version
    def v_cal(self,sheetdata):
        sum_v = [[0 for i in range(self.terminal-1)]]

        for i in range(self.sample_size):
            temp_v = [[0 for k in range(self.terminal-1)]]
            for j in range(self.terminal-1):
                temp_v[0][j] = sheetdata.cell_value(i,j+1)-sheetdata.cell_value(i,j)
                temp_v[0][j] = temp_v[0][j]/self.interval
            if(i == 0):
                sum_v = temp_v
            else:
                sum_v += temp_v

        return sum_v

    #list version
    def v_cal_list(self,sheetdata):
        sum_v = [[0 for i in range(self.terminal-1)]]

        for i in range(self.sample_size):
            temp_v = [[0 for k in range(self.terminal-1)]]
            for j in range(self.terminal-1):
                temp_v[0][j] = sheetdata[i][j+1]-sheetdata[i][j]
                temp_v[0][j] /= self.interval
            if(i == 0):
                sum_v = temp_v
            else:
                sum_v += temp_v    

        return sum_v

    def variable_v_len(self,Vx,Vy,Vz):
        v_len_matrix = [[0 for i in range(self.terminal-1)] for j in range(self.sample_size)]
        v_square = [[0 for i in range(self.terminal-1)] for j in range(self.sample_size)]
        result = [0 for i in range(self.terminal-1)]
        sum_square = [0 for i in range(self.terminal-1)]
        vector_sum = [0 for i in range(self.terminal-1)]
        vector_sum_x = [0 for i in range(self.terminal-1)]
        vector_sum_y = [0 for i in range(self.terminal-1)]
        vector_sum_z = [0 for i in range(self.terminal-1)]
        for i in range(self.sample_size):
            for j in range(self.terminal-1):
                v_square[i][j] = Vx[i][j]*Vx[i][j]+Vy[i][j]*Vy[i][j]+Vz[i][j]*Vz[i][j]
                v_len_matrix[i][j] = math.sqrt(v_square[i][j])

                result[j] += v_len_matrix[i][j]
                sum_square[j] += v_square[i][j]
                vector_sum_x[j] += Vx[i][j]
                vector_sum_y[j] += Vy[i][j]
                vector_sum_z[j] += Vz[i][j]

        self.v_direction_detect(v_len_matrix,Vx,'x')
        self.v_direction_detect(v_len_matrix,Vy,'y')
        self.v_direction_detect(v_len_matrix,Vz,'z')
        self.drawCumulativeHist(v_len_matrix)
        self.drawHist(v_len_matrix)

        #calculate the mean of velocity
        for i in range(self.terminal-1):
            result[i] /= self.sample_size
            sum_square[i] /= self.sample_size
            sum_square[i] = sum_square[i]/self.sample_size-result[i]*result[i]
            result[i] *= self.sample_size
            vector_sum[i] = math.sqrt(vector_sum_x[i]*vector_sum_x[i]+vector_sum_y[i]*vector_sum_y[i]+vector_sum_z[i]*vector_sum_z[i])

        #sum_square:variable  result:mean*sample_size vector_sum:length of the sum of vectors
        return (sum_square,result,vector_sum)

    #calculate the value of random_index
    def random_index(self,variable_v,mean_v,sum_vec):
        result = [0 for i in range(self.terminal-1)]
        for i in range(self.terminal-1):
            result[i] = mean_v[i]*self.K
            result[i] /= self.length_box*self.length_box*self.length_box*self.length_dro
            result[i] /= 1+variable_v[i]
            result[i] /= 1+sum_vec[i]/self.length_dro

        return result

    def v_direction_detect(self,velocity,one_dir_v,direct):
        v_length = []
        v_one_dir = []
        for i in range(self.sample_size):
            v_length += velocity[i]
            v_one_dir += one_dir_v[i]
        for i in range(len(v_one_dir)):
            v_one_dir[i] /= v_length[i]
            v_one_dir[i] = math.acos(v_one_dir[i])
        pyplot.hist(v_one_dir,300)
        pyplot.xlabel('velocity_direction_'+direct)
        pyplot.ylabel('frequency')
        pyplot.title('_frequency_statistic_plot of v_direction_'+direct)
        pyplot.show()        

def cpp_invoke():
    data = Data_manipulate(246,0.01,1,0.2,19,100)
    Sx = data.data_input('D:\\FDU\\Template\\CS\\数学建模\\S.xlsx','Sx')
    Vx = data.v_cal(Sx)
    Sy = data.data_input('D:\\FDU\\Template\\CS\\数学建模\\S.xlsx','Sy')
    Vy = data.v_cal(Sy)
    Sz = data.data_input('D:\\FDU\\Template\\CS\\数学建模\\S.xlsx','Sz')
    Vz = data.v_cal(Sz)   
    #variable of length_velocity 
    temp = data.variable_v_len(Vx,Vy,Vz)
    variable_v = temp[0]
    mean_v = temp[1]
    sum_vec = temp[2]
    result = data.random_index(variable_v,mean_v,sum_vec)

if __name__ == '__main__':
    data = Data_manipulate(246,0.01,1,0.2,19,100)
    Sx = data.data_input('D:\\FDU\\Template\\CS\\数学建模\\S.xlsx','Sx')
    Vx = data.v_cal(Sx)
    Sy = data.data_input('D:\\FDU\\Template\\CS\\数学建模\\S.xlsx','Sy')
    Vy = data.v_cal(Sy)
    Sz = data.data_input('D:\\FDU\\Template\\CS\\数学建模\\S.xlsx','Sz')
    Vz = data.v_cal(Sz)   
    #variable of length_velocity 
    temp = data.variable_v_len(Vx,Vy,Vz)
    variable_v = temp[0]
    mean_v = temp[1]
    sum_vec = temp[2]
    result = data.random_index(variable_v,mean_v,sum_vec)

