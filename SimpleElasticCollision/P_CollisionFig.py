# coding=utf-8
from matplotlib import pyplot as plt
from scipy.special import comb
import numpy as np

def draw_pic(filepath):
	LifeTime = 5000
	FlyNum = 500
	Fps = 0.5
	TotalNum = comb(FlyNum,2)
	FrameIndex = range(0,500)
	ProbCollid = []
	#read data from .txt
	counter = 0
	colli_time = 0
	with open(filepath,'r') as delta_col:
		for i in range(int(LifeTime/Fps)):
			lines = delta_col.readline()
			if counter < 19:
				counter += 1
				colli_time += float(lines)
			else:
				ProbCollid.append(colli_time/(TotalNum+.0))
				counter = 0
				colli_time = 0

	#draw P_F fig
	plt.plot(FrameIndex,ProbCollid,label = 'Collid_Prob--Frame',linewidth = 1,color = 'r',marker = 'o',markerfacecolor = 'blue',markersize = 1)
	#plt.plot(FrameIndex,ProbCollid,lable = 'P--F')
	plt.xlabel('Frame')
	plt.ylabel('Colliding Probability')
	plt.title('P--F figure')
	plt.legend()
	plt.show()

if __name__ == '__main__':
	draw_pic("D:\\FDU\\NeuroScience\\1904FruitflyExp\\190501\\step0.5\\coor_cpp_9.txt")