include(CheckIncludeFiles)

check_include_files(pthread.h HAVE_PTHREAD_H)
check_include_files(openssl/ssl.h HAVE_OPENSSL_H)

find_library(HAVE_PTHREAD_L pthread)
find_library(HAVE_OPENSSL_L ssl)

configure_file(config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# install libyar directory
install(
    DIRECTORY bedawang
    DESTINATION include
    FILES_MATCHING PATTERN "*.txt" EXCLUDE
)
