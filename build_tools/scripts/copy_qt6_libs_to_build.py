import sys, platform, glob, shutil


def copyQt6LibsToBuild(qtLibName, destination, qtPath, build_type):
    if platform.system() == 'Windows':
        # Appending 'd' if we need a debug version of the lib
        if build_type == 'Debug':
            qtLibName = qtLibName + 'd'
        # Appending '.dll' extention
        qtLibName = qtLibName + '.dll'
        # Getting the lib
        libsList = glob.glob(qtPath + qtLibName)
        # Checking whether it exists or not
        if not libsList:
            sys.exit(
                'The "%s" lib was not found in "%s". Check the correctness of spelling.'
                %(qtLibName, qtPath)
            )
        # Copying founded libs to the destination
        for lib in libsList:
            print(
                'Copying the "%s" lib to the "%s" folder.'
                %(qtLibName,destination)
            )
            shutil.copy(lib, destination)


if __name__ == "__main__":
    copyQt6LibsToBuild(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])