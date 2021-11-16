

set(SOURCES rsa.cc)

add_library(rsa_lib STATIC ${SOURCES})


target_link_libraries(
    rsa_lib
    big_int_lib  
    project_options 
    project_warnings
    )

target_include_directories(
    rsa_lib
    PRIVATE ${RSA_INC_DIR}
)
