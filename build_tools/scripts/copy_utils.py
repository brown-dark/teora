import distutils.dir_util, sys, os


def copyFolderRecurcievely(from_where, to_where, folder_name):
    # Creating the desired folder in destination if not exist
    to_where = to_where + '/' + folder_name
    if not os.path.exists(to_where):
        os.mkdir(to_where)

    # Copying found folder to the destination
    print(
        'Copying the "%s" folder to the "%s" folder.'
        %(from_where, to_where)
    )
    distutils.dir_util.copy_tree(from_where, to_where)


if __name__ == "__main__":
    copyFolderRecurcievely(sys.argv[1], sys.argv[2], sys.argv[3])