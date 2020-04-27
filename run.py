from os import listdir
import sys
import subprocess

def run():
	
	if len(sys.argv) < 2:
		print("Error! Unspecified method")
		return -1;
	
	for inputFile in listdir("In/"):
		
		outputFile = inputFile[:len(inputFile)-2] + "out"
		
		if (sys.argv[1] == "quick" or sys.argv[1] == "Quick"):
			
			if len(sys.argv) < 3:
				print("Error! Unspecified quick sort mode")
				return -2;
 
			process = subprocess.Popen("./sortingAlgorithms" + " " + sys.argv[1] + " " + inputFile + " " + outputFile + " " + sys.argv[2], shell = True)
		
		else:
			process = subprocess.Popen("./sortingAlgorithms" + " " + sys.argv[1] + " " + inputFile + " " + outputFile, shell = True)

		process.wait()
run()
