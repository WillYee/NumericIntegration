import os
import math
from subprocess import Popen, PIPE

START_NUM_THREAD = 1
END_NUM_THREAD = 9

BASE = 2
UPPERBOUND = 19

def main():
	
	
	print "num_thread,num_divisions,time,total_volume"

	for thread_num in range(START_NUM_THREAD, END_NUM_THREAD):
		for subdivision_num in range(0, UPPERBOUND):
			process = Popen(["./build/NumericIntegration", "-D", str(math.pow(2,subdivision_num)), "-T", str(thread_num)], stdout = PIPE)
			(output, err) = process.communicate()
			process.wait()
			print str(thread_num) + "," + str(math.pow(2,subdivision_num)) + "," + output.rstrip()
	return

if __name__ == "__main__":
	main()
