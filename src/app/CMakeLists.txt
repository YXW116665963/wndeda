# message(STATUS "main:CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
project(wndeda_app)

# Request the required wxWidgets libs
find_package(wxWidgets 3.3 COMPONENTS core base REQUIRED CONFIG)
# perhaps not work
if(WIN32)
    # Include a RC file for windows
    list(APPEND SRC_FILES ../sample.rc)
elseif(APPLE)
    # Add an icon for the apple .app file
    list(APPEND SRC_FILES ../../src/osx/carbon/wxmac.icns)
endif()
# perhaps not work
if(MSVC)
    # Use manifest from wx.rc
    set_target_properties(${PROJECT_NAME} PROPERTIES
        COMPILE_FLAGS "/DwxUSE_RC_MANIFEST"
        LINK_FLAGS "/MANIFEST:NO"
    )
elseif(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        RESOURCE "../../src/osx/carbon/wxmac.icns"
        MACOSX_BUNDLE_ICON_FILE wxmac.icns
        MACOSX_BUNDLE_COPYRIGHT "Copyright wxWidgets"
        MACOSX_BUNDLE_GUI_IDENTIFIER "org.wxwidgets.minimal"
    )
endif()

# Define a variable containing a list of source files for the project
file(GLOB_RECURSE APP_HEADERS *.h)
file(GLOB_RECURSE APP_CPPS *.cpp)

set(APP_ALL_SRC ${APP_HEADERS} ${APP_CPPS})

# Set the wxWidgets include directories
include_directories(${APPSRC_PATH}/frame)
include_directories(${APPSRC_PATH})

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${APP_ALL_SRC})

message(STATUS "APPSRC_PATH: ${APPSRC_PATH}")
# Set the wxWidgets libraries to link against
target_link_libraries(${PROJECT_NAME}
PUBLIC
wxWidgets::wxWidgets)