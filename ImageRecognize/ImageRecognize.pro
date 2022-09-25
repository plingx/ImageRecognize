#-------------------------------------------------
#
# Project created by QtCreator 2022-07-05T22:36:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageRecognize
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    base/base.h \
    base/base64.h \
    base/http.h \
    base/utils.h \
    ocr.h

FORMS    += widget.ui

INCLUDEPATH += /usr/local/curl/include       \
               /usr/local/json/include       \
               /usr/local/openssl/include    \
               /usr/local/opencv-2.4.9/include \
               /usr/local/opencv-2.4.9/include/opencv \
               /usr/local/opencv-2.4.9/include/opencv2 \

LIBS += /usr/local/curl/lib/libcurl.so.4.5.0     \
        /usr/local/json/lib/libjsoncpp.so        \
        /usr/local/openssl/lib/libssl.so.1.0.0   \
        /usr/local/openssl/lib/libcrypto.so.1.0.0  \
        /usr/local/opencv-2.4.9/lib/libopencv*     \
        /usr/local/opencv-2.4.9/lib/libv4l1*       \
        /usr/local/opencv-2.4.9/lib/libv4l2*       \
        /usr/local/opencv-2.4.9/lib/libv4lc*       \
