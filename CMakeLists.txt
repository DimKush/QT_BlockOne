cmake_minimum_required(VERSION 3.5)
project(Block_One_Task_One)

find_package(Qt4 COMPONENTS QTCORE QTGUI)

find_package(Qt5Widgets)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (QT_LIB_SRC  ${PROJECT_SOURCE_DIR}/mainwindow/mainwindow.cpp)
set (QT_LIB_HEAD ${PROJECT_SOURCE_DIR}/mainwindow/mainwindow.hpp)

set (QT_LIB_UI_MAIN ${PROJECT_SOURCE_DIR}/mainwindow/mainwindow.ui)

# _TASK_ONE_
set (QT_TASK_ONE_DLG_SRC  ${PROJECT_SOURCE_DIR}/TaskOneDlg/TaskOneDlg.cpp)
set (QT_TASK_ONE_DLG_HEAD ${PROJECT_SOURCE_DIR}/TaskOneDlg/TaskOneDlg.hpp)
set (TASK_ONE_LOGIC_SRC ${PROJECT_SOURCE_DIR}/TaskOneDlg/TaskOneLogic.cpp)
set (TASK_ONE_LOGIC_HEAD ${PROJECT_SOURCE_DIR}/TaskOneDlg/TaskOneLogic.hpp)

set (QT_LIB_UI_TASK_ONE ${PROJECT_SOURCE_DIR}/TaskOneDlg/taskonedlg.ui)

# _TASK_TWO_
set (QT_TASK_TWO_DLG_SRC  ${PROJECT_SOURCE_DIR}/TaskTwoDlg/TaskTwoDlg.cpp)
set (QT_TASK_TWO_DLG_HEAD ${PROJECT_SOURCE_DIR}/TaskTwoDlg/TaskTwoDlg.hpp)
set (TASK_TWO_LOGIC_SRC ${PROJECT_SOURCE_DIR}/TaskTwoDlg/TaskTwoLogic.cpp)
set (TASK_TWO_LOGIC_HEAD ${PROJECT_SOURCE_DIR}/TaskTwoDlg/TaskTwoLogic.hpp)

set (QT_LIB_UI_TASK_TWO ${PROJECT_SOURCE_DIR}/TaskTwoDlg/tasktwodialog.ui)

# _TASK_THREE_
set (QT_TASK_THREE_DLG_SRC  ${PROJECT_SOURCE_DIR}/TaskThreeDlg/TaskThreeDlg.cpp)
set (QT_TASK_THREE_DLG_HEAD ${PROJECT_SOURCE_DIR}/TaskThreeDlg/TaskThreeDlg.hpp)

set (QT_LIB_UI_TASK_THREE ${PROJECT_SOURCE_DIR}/TaskThreeDlg/taskthreedlg.ui)

# _TASK_FOUR_
set (QT_TASK_FOUR_DLG_SRC  ${PROJECT_SOURCE_DIR}/TaskFourDlg/TaskFourDialog.cpp)
set (QT_TASK_FOUR_DLG_HEAD ${PROJECT_SOURCE_DIR}/TaskFourDlg/TaskFourDialog.hpp)

set (QT_LIB_UI_TASK_FOUR ${PROJECT_SOURCE_DIR}/TaskFourDlg/taskfourdialog.ui)


qt5_wrap_cpp(QT_LIB_HEAD_MOC
            ${QT_LIB_HEAD}
            )

qt5_wrap_ui(QT_LIB_UI_MOC
            ${QT_LIB_UI_MAIN}
            )

qt5_wrap_cpp(QT_TASKS_HEAD_MOC
            ${QT_TASK_ONE_DLG_HEAD}
            ${TASK_ONE_LOGIC_HEAD}
            ${QT_TASK_TWO_DLG_HEAD}
            ${TASK_TWO_LOGIC_HEAD}
            ${QT_TASK_THREE_DLG_HEAD}
            ${QT_TASK_FOUR_DLG_HEAD}
            )

qt5_wrap_ui(QT_TASKS_UI_MOC
            ${QT_LIB_UI_TASK_ONE}
            ${QT_LIB_UI_TASK_TWO}
            ${QT_LIB_UI_TASK_THREE}
            ${QT_LIB_UI_TASK_FOUR}
            )

include_directories (${PROJECT_SOURCE_DIR})

# build WindowsMain
add_library(MainLib SHARED
            ${QT_LIB_SRC}
            ${QT_LIB_HEAD_MOC}
            ${QT_LIB_UI_MOC}
            )

add_library(TasksLib SHARED
            ${QT_TASKS_HEAD_MOC}
            ${QT_TASKS_UI_MOC}

            ${QT_TASK_ONE_DLG_SRC}
            ${TASK_ONE_LOGIC_SRC}

            ${QT_TASK_TWO_DLG_SRC}
            ${TASK_TWO_LOGIC_SRC}

            ${QT_TASK_THREE_DLG_SRC}

            ${QT_TASK_FOUR_DLG_SRC}
            )

target_link_libraries(MainLib Qt5::Widgets)
target_link_libraries(TasksLib Qt5::Widgets)

target_link_libraries(MainLib TasksLib)

add_executable(${PROJECT_NAME}
               main.cpp
               )

target_link_libraries(${PROJECT_NAME}
                      MainLib
                      )

target_include_directories(${PROJECT_NAME} PRIVATE TaskOneDlg)
target_include_directories(${PROJECT_NAME} PRIVATE TaskTwoDlg)
target_include_directories(${PROJECT_NAME} PRIVATE TaskThreeDlg)
target_include_directories(${PROJECT_NAME} PRIVATE TaskFourDlg)
