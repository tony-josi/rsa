option(MAIN_TEST_EXE "Enable main test exe build" ON)

if(MAIN_TEST_EXE)
    message("Builds main test exe ")
    set(SOURCES test_main.cc)  
    add_executable(rsa_test_exe ${SOURCES})
    target_link_libraries(
        rsa_test_exe  
        project_options 
        project_warnings 
        rsa_lib)
endif()

target_include_directories(
    rsa_test_exe
    PRIVATE ${RSA_INC_DIR} ${BI_LIB_INC_DIR}
)