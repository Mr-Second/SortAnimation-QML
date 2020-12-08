QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14 sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fmt/format.cc \
    fmt/os.cc \
    main.cpp \
    board.cpp

HEADERS += \
    BubbleSort.hpp \
    ISort.hpp \
    InsertSort.hpp \
    MergeSort.hpp \
    QuickSort.hpp \
    RandomGenerator.hpp \
    SelectSort.hpp \
    ShellSort.hpp \
    board.h \
    fmt/chrono.h \
    fmt/color.h \
    fmt/compile.h \
    fmt/core.h \
    fmt/format-inl.h \
    fmt/format.h \
    fmt/locale.h \
    fmt/os.h \
    fmt/ostream.h \
    fmt/posix.h \
    fmt/printf.h \
    fmt/ranges.h

FORMS += \
    board.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
