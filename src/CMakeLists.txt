

set(BI_LIB_INC_DIR "${PROJECT_SOURCE_DIR}/src/internal_inc")
set(RSA_INC_DIR "${PROJECT_SOURCE_DIR}/inc")


if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_subdirectory(big_int)
add_subdirectory(rsa)
add_subdirectory(test_main)

