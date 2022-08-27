import distutils.dir_util, sys, os


def copyQt6PlatformsToBuild(destination, qtPath):
    # Creating the 'platforms' folder in build directory
    destination = destination + '/' + 'platforms'
    if not os.path.exists(destination):
        os.mkdir(destination)
    # Copying founded platform libs to the destination
    print(
        'Copying the "%s" folder to the "%s" folder.'
        %(qtPath, destination)
    )
    distutils.dir_util.copy_tree(qtPath, destination)


if __name__ == "__main__":
    copyQt6PlatformsToBuild(sys.argv[1], sys.argv[2])