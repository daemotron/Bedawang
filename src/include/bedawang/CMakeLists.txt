# define header files
set(
	BEDAWANG_HEADER_FILES
	mpm_prethread.h
	version.h
)

# install header files
install(
	FILES ${BEDAWANG_HEADER_FILES}
	DESTINATION include/bedawang
)
