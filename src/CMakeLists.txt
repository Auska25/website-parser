include_directories ( 	/usr/include/libxml++-2.6/
						/usr/include/libxml2/
						/usr/include/glibmm-2.4/
						/usr/lib/x86_64-linux-gnu/glibmm-2.4/include/
						/usr/include/glib-2.0/
						/usr/lib/x86_64-linux-gnu/glib-2.0/include/
						/usr/lib/libxml++-2.6/include/
					)
					
find_package( Boost REQUIRED COMPONENTS program_options )

include_directories( ${Boost_INCLUDE_DIRS} )
					
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(html)

set ( website_parser_srcs 
		main.cpp
		config_cmdline.cpp
	)

add_executable( website-parser ${website_parser_srcs} )

set ( website_parser_libs 
		auska25_html
		curlpp
		curl
		xml++-2.6
		xml2
		glibmm-2.4
		giomm-2.4
	)

target_link_libraries( website-parser ${website_parser_libs} ${Boost_PROGRAM_OPTIONS_LIBRARY})
