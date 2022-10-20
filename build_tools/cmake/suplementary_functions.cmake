#-------------------------------------------------------------------#
# cmake version

cmake_minimum_required(VERSION 3.20)

#-------------------------------------------------------------------#
# create build directory

function(CreateBuildDirectory BUILD_DIR_PATH)
    file(MAKE_DIRECTORY ${BUILD_DIR_PATH})
endfunction(CreateBuildDirectory)

#-------------------------------------------------------------------#
# copy Qt Dll

function(CopyQtDll LIB_NAME)
    execute_process(
        COMMAND python3 ${TEORA_ROOT_DIR}/build_tools/scripts/copy_qt6_libs_to_build.py
        ${LIB_NAME}
        ${TEORA_BUILD_DIR}
        ${QT6_FULL_PATH}/bin/
        ${CMAKE_BUILD_TYPE}
    )
endfunction(CopyQtDll)

#-------------------------------------------------------------------#
# Copy Qt 'platforms' folder

function(CopyQtPlatforms)
    execute_process(
        COMMAND python3 ${TEORA_ROOT_DIR}/build_tools/scripts/copy_utils.py
        ${QT6_FULL_PATH}/plugins/platforms/
        ${TEORA_BUILD_DIR}
        "platforms"
    )
endfunction(CopyQtPlatforms)

#-------------------------------------------------------------------#
# Copy icons folder

function(CopyIcons)
    execute_process(
        COMMAND python3 ${TEORA_ROOT_DIR}/build_tools/scripts/copy_utils.py
        ${TEORA_ROOT_DIR}/resources/icons/
        ${TEORA_BUILD_DIR}
        "icons"
    )
endfunction(CopyIcons)

#-------------------------------------------------------------------#