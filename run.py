from os import listdir
import sys
import subprocess

def run():
	for inputFile in listdir("In/"):
		
		outputFile = inputFile[:len(inputFile)-2] + "out"
		process = subprocess.Popen("./sortingAlgorithms" + " " + sys.argv[1] + " " + inputFile + " " + outputFile, shell = True)
		process.wait()
run()
