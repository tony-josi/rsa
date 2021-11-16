

set(BI_LIB_INC_DIR "${PROJECT_SOURCE_DIR}/src/inc")

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_subdirectory(big_int)

