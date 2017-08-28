#-------------------------------------------------
#
# Project created by QtCreator 2017-01-24T12:53:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageResizerCUDA
TEMPLATE = app

# Disables debug output in Release mode:

#CONFIG(release)
#{
#    DEFINES+=QT_NO_DEBUG_OUTPUT
#}


CONFIG(debug, debug|release) {
    # Debug mode
    DESTDIR = debug
    OBJECTS_DIR = debug/obj
    CUDA_OBJECTS_DIR = debug/cuda
}
else
{
    # Release mode
    DESTDIR = release
    OBJECTS_DIR = release/obj
    CUDA_OBJECTS_DIR = release/cuda
}
SOURCES += main.cpp\
        mainwindow.cpp \
    graphicssceneex.cpp \
    graphicsviewex.cpp \
    text.cpp \
    io.cpp

# This makes the .cu files appear in your project
OTHER_FILES += cuda.cu

QMAKE_LFLAGS += /INCREMENTAL:NO


MSVCRT_LINK_FLAG_DEBUG = "/MDd"

MSVCRT_LINK_FLAG_RELEASE = "/MD"

CUDA_SOURCES += cuda.cu
CUDA_DIR = "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v8.0"   # Path to cuda toolkit install
SYSTEM_NAME = Win32         # Depending on your system either 'Win32', 'x64', or 'Win64'
SYSTEM_TYPE = 32            # '32' or '64', depending on your system
CUDA_ARCH = sm_21      # Type of CUDA architecture
NVCC_OPTIONS = --use_fast_math --compiler-bindir="C:/PROGRA~2/VS2013/VC/bin" --cl-version 2013 --verbose

HEADERS  += mainwindow.h \
    graphicssceneex.h \
    graphicsviewex.h \
    text.h \
    io.h \
    colordefs.h \
    decimal.h

FORMS    += mainwindow.ui

# include paths
INCLUDEPATH += $$CUDA_DIR/include

# library directories
QMAKE_LIBDIR += $$CUDA_DIR/lib/$$SYSTEM_NAME

# Add the necessary libraries
CUDA_LIBS = cuda cudart
# The following makes sure all path names (which often include spaces) are put between quotation marks
CUDA_INC = $$join(INCLUDEPATH,'" -I"','-I"','"')
# LIBRARIES IN FORMAT NEEDED BY NVCC
NVCC_LIBS = $$join(CUDA_LIBS,' -l','-l', '')
# LIBRARIES IN FORMAT NEEDED BY VISUAL C++ LINKER
LIBS += cuda.lib
LIBS += cudart.lib

# The following library conflicts with something in Cuda
QMAKE_LFLAGS_RELEASE = /NODEFAULTLIB:libcmt.lib
QMAKE_LFLAGS_DEBUG   = /NODEFAULTLIB:libcmt.lib

# Configuration of the Cuda compiler
CONFIG(debug, debug|release) {
    # Debug mode
    cuda_d.input = CUDA_SOURCES
    cuda_d.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.o
    cuda_d.commands = "$$CUDA_DIR/bin/nvcc.exe" -D_DEBUG $$NVCC_OPTIONS $$CUDA_INC $$NVCC_LIBS --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME} -Xcompiler $$MSVCRT_LINK_FLAG_DEBUG
    cuda_d.dependency_type = TYPE_C
    QMAKE_EXTRA_COMPILERS += cuda_d
}
else {
    # Release mode
    cuda.input = CUDA_SOURCES
    cuda.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.o
    cuda.commands = "$$CUDA_DIR/bin/nvcc.exe" $$NVCC_OPTIONS $$CUDA_INC $$NVCC_LIBS --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME} -Xcompiler $$MSVCRT_LINK_FLAG_RELEASE
    cuda.dependency_type = TYPE_C
    QMAKE_EXTRA_COMPILERS += cuda
}
