context = {
"src_project_name"  : "undefined",
"dst_project_name"  : "undeifned",
"src_project_path"  : "undefined",
"dst_project_path"  : "undefined",
"script_dir"        : "undefined",
}


import sys
import os, os.path
import json
import shutil

def dumpUsage():
    print("Usage: create_project.py -project PROJECT_NAME")
    print("Options:")
    print("  -project   PROJECT_NAME          Project name, for example: MyGame\n")
    print("Sample 1: ./create_project.py -project MyGame\n")

def checkParams(context):
	context["script_dir"] = os.getcwd() + "/"
	if len(sys.argv) < 3:
		dumpUsage()
		sys.exit()

	if "-project" == sys.argv[1]:
		context["dst_project_name"] = sys.argv[2]
		context["dst_project_path"] = os.getcwd() + "/../projects/" + context["dst_project_name"]
	else:
		print("Invalid -project parameter")
		sys.exit()

	context["src_project_name"] = "CappuccinoTemplate"
	context["src_project_path"] = os.getcwd() + "/../template/default-cpp"
#end-of checkParams

def replaceStringInFile(filepath, src_string, dst_string):
    content = ""
    f1 = open(filepath, "r")
    for line in f1:
        if src_string in line:
            content += line.replace(src_string, dst_string)
        else:
            content += line
    f1.close()
    f2 = open(filepath, "w")
    f2.write(content)
    f2.close()
# end-of replaceStringInFile

def processPlatformProjects(platform):
    # determine proj_path
    proj_path = context["dst_project_path"] + '/'
    java_package_path = ""
    # read josn config file or the current platform
    f = open("%s.json" % platform)
    data = json.load(f)

    # rename files and folders
    for i in range(0, len(data["rename"])):
        tmp = data["rename"][i].replace("PACKAGE_PATH", java_package_path)
        src = tmp.replace("PROJECT_NAME", context["src_project_name"])
        dst = tmp.replace("PROJECT_NAME", context["dst_project_name"])
        if (os.path.exists(proj_path + src) == True):
            os.rename(proj_path + src, proj_path + dst)
    
    # rename project_name
    for i in range(0, len(data["replace_project_name"])):
        tmp = data["replace_project_name"][i].replace("PACKAGE_PATH", java_package_path)
        dst = tmp.replace("PROJECT_NAME", context["dst_project_name"])
        replaceStringInFile(proj_path + dst, context["src_project_name"], context["dst_project_name"])
        if (os.path.exists(proj_path + dst) == True):
            replaceStringInFile(proj_path + dst, context["src_project_name"], context["dst_project_name"])
# end of processPlatformProjects

checkParams(context)
if (os.path.exists(context["dst_project_path"]) == True):
    print("Error:" + context["dst_project_path"] + " folder is already existing")
    print("Please remove the old project or choose a new PROJECT_NAME in -project parameter")
    sys.exit()

shutil.copytree(context["src_project_path"], context["dst_project_path"], True)
processPlatformProjects("win32")
print("New project has been created in this path: " + context["dst_project_path"].replace("tools/../projects/", ""))
print("Have Fun!")