QT += quick

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS QT_QML_DEBUG_NO_WARNING

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    fmt/format.cc \
    fmt/os.cc

RESOURCES += qml.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    BubbleSort.hpp \
    ISort.hpp \
    RandomGenerator.hpp \
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

