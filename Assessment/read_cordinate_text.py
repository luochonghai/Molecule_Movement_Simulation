import random_index_cal
import ast

SIZE = 100
TERMINAL = 1000

def read_coordinate_from_text(file_path,height,width):
	Cx = [[0 for i in range(width+1)] for j in range(height)]
	Cy = [[0 for i in range(width+1)] for j in range(height)]
	Cz = [[0 for i in range(width+1)] for j in range(height)]
	counter = 0
	with open(file_path,'r') as file_to_read:
		while True:
			lines = file_to_read.readline()
			if not lines:
				break
				pass
			index,cx,cy,cz = lines.split()
			Cx[int(ast.literal_eval(index))][int(counter/SIZE)] = ast.literal_eval(cx)
			Cy[int(ast.literal_eval(index))][int(counter/SIZE)] = ast.literal_eval(cy)
			Cz[int(ast.literal_eval(index))][int(counter/SIZE)] = ast.literal_eval(cz)
			counter += 1	

	file_to_read.close()
	return Cx,Cy,Cz

def model_evaluation():
	Cx,Cy,Cz = read_coordinate_from_text('D:\\FDU\\Template\\CS\\数学建模\\coordinate.txt',SIZE,TERMINAL)
	data = random_index_cal.Data_manipulate(SIZE,0.1,1,1,60,TERMINAL)
	Vx = data.v_cal_list(Cx)
	Vy = data.v_cal_list(Cy)
	Vz = data.v_cal_list(Cz)
	temp = data.variable_v_len(Vx,Vy,Vz)
	variable_v = temp[0]
	mean_v = temp[1]
	sum_vec = temp[2]
	result = data.random_index(variable_v,mean_v,sum_vec)

if __name__ == '__main__':
	model_evaluation()
