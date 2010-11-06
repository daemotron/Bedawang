include_directories(${bedawang_SOURCE_DIR}/src/include ${bedawang_SOURCE_DIR}/src/lib ${bedawang_BINARY_DIR}/src/include)

# source files that should be compiled into the library have
# to be added to this list
set(
	BEDAWANG_SOURCEFILES
	buffer.c
)

# check whether libssl can be used
find_library(SSL_LIB ssl)
if(SSL_LIB)
	list(APPEND BEDAWANG_LIBRARIES ${SSL_LIB})
endif(SSL_LIB)

# check whether libpthread can be used
find_library(PTHREAD_LIB pthread)
if(PTHREAD_LIB)
 	list(APPEND BEDAWANG_LIBRARIES ${PTHREAD_LIB})
endif(PTHREAD_LIB)

# build shared library binary
add_library(bedawang SHARED ${BEDAWANG_SOURCEFILES})

# link it to other libs
if(BEDAWANG_LIBRARIES)
	target_link_libraries(bedawang ${BEDAWANG_LIBRARIES})
endif(BEDAWANG_LIBRARIES)

set_target_properties(bedawang PROPERTIES VERSION ${BEDAWANG_LIBVERSION} SOVERSION ${BEDAWANG_LIBVERSION})

install(
	TARGETS bedawang
	LIBRARY DESTINATION lib
)