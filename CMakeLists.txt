

cmake_minimum_required(VERSION 2.8)
project(wxWidgetsLetsPlay)

add_compile_options(-std=c++14)
add_compile_options(-O2)

if(CMAKE_BUILD_TYPE STREQUAL "Build")
    add_compile_options(-g)
endif()


add_subdirectory(${PROJECT_SOURCE_DIR}/src)

if(UNIX)
    link_directories(${PROJECT_SOURCE_DIR}/ext/linux/lib)

    include_directories(${PROJECT_SOURCE_DIR}/src/
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/ext/linux/include/wx-3.1
        ${PROJECT_SOURCE_DIR}/ext/linux/lib/wx/include/gtk2-unicode-3.1/
    )

    add_compile_options(-D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread)
endif(UNIX)
if(WIN32)
    link_directories(${PROJECT_SOURCE_DIR}/ext/windows/lib)
	
	include_directories(${PROJECT_SOURCE_DIR}/src/
		${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/ext/windows/include
        ${PROJECT_SOURCE_DIR}/ext/windows/lib/mswu
		)

endif(WIN32)

add_executable(wxwidgetsletsplay
    ${SOURCE}
    ${HEADERS}
)

if(WIN32)
    add_custom_command(
 	 TARGET wxwidgetsletsplay POST_BUILD
 	 COMMAND ${CMAKE_COMMAND} -E copy 
  	 ${CMAKE_SOURCE_DIR}/ext/windows/lib/wxbase312u_gcc_custom.dll
	  ${CMAKE_BINARY_DIR}/bin/wxbase312u_gcc_custom.dll
	)

    add_custom_command(
 	 TARGET wxwidgetsletsplay POST_BUILD
 	 COMMAND ${CMAKE_COMMAND} -E copy 
  	 ${CMAKE_SOURCE_DIR}/ext/windows/lib/wxmsw312u_core_gcc_custom.dll
	  ${CMAKE_BINARY_DIR}/bin/wxmsw312u_core_gcc_custom.dll
	)
endif(WIN32)

set_target_properties(wxwidgetsletsplay PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(wxwidgetsletsplay
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)   

if(UNIX)
    target_link_libraries(wxwidgetsletsplay pthread wx_gtk2u_xrc-3.1 wx_gtk2u_html-3.1 wx_gtk2u_qa-3.1 wx_gtk2u_core-3.1 wx_baseu_xml-3.1 wx_baseu_net-3.1 wx_baseu-3.1)
elseif(WIN32)
    target_link_libraries(wxwidgetsletsplay wxbase31u wxexpat wxmsw31u_adv wxmsw31u_aui wxmsw31u_core wxmsw31u_gl wxmsw31u_html wxmsw31u_media wxmsw31u_propgrid wxmsw31u_qa wxmsw31u_ribbon wxmsw31u_richtext wxmsw31u_stc wxmsw31u_webview wxmsw31u_xrc wxjpeg wxpng wxregexu wxscintilla wxtiff wxzlib)
endif()
