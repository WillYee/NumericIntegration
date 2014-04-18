import os
from subprocess import Popen, PIPE

START_NUM_THREAD = 1
END_NUM_THREAD = 9

START_SUBDIVISIONS = 100
END_SUBDIVISIONS = 40000

def main():
	
	
	print "num_thread,num_divisions,time,total_volume"

	for thread_num in range(START_NUM_THREAD, END_NUM_THREAD):
		for subdivision_num in range(START_SUBDIVISIONS, END_SUBDIVISIONS, 500):
			process = Popen(["./Assign1", "-D", str(subdivision_num), "-T", str(thread_num)], stdout = PIPE)
			(output, err) = process.communicate()
			process.wait()
			print str(thread_num) + "," + str(subdivision_num) + "," + output.rstrip()
	return

if __name__ == "__main__":
	main()
