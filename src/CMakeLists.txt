set(CMAKE_CXX_FLAGS "-std=c++11")

add_subdirectory(html)

set ( website_parser_srcs 
		main.cpp
	)

add_executable( website-parser ${website_parser_srcs} )

set ( website_parser_libs 
		auska25_html
		curlpp
		curl
	)

target_link_libraries( website-parser ${website_parser_libs} )

set_property(TARGET website-parser PROPERTY CXX_STANDARD 11)