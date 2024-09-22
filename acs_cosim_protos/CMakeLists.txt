cmake_minimum_required (VERSION 3.15)
project ("acs_cosim_protos")

find_package (Protobuf CONFIG REQUIRED)

add_library(
    ${PROJECT_NAME} STATIC
    "${CMAKE_CURRENT_LIST_DIR}/proto/control_input.proto"
)
target_link_libraries(${PROJECT_NAME} PUBLIC protobuf::libprotobuf)
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>" "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

protobuf_generate(
    TARGET ${PROJECT_NAME}
    PROTOC_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}"
    LANGUAGE cpp
    OUT_VAR PROTOS_GENERATED
)

set(PROTOS_GENERATED_HEADERS ${PROTOS_GENERATED})
list(FILTER PROTOS_GENERATED_HEADERS INCLUDE REGEX "^.*\\.h(h|pp)?$")

install(FILES ${PROTOS_GENERATED_HEADERS}
        DESTINATION "include/${PROJECT_NAME}")

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}_config
        ARCHIVE DESTINATION "lib"
        INCLUDES DESTINATION "include"
)

install(EXPORT ${PROJECT_NAME}_config
        FILE ${PROJECT_NAME}.cmake
        NAMESPACE ${PROJECT_NAME}::${PROJECT_NAME}
        DESTINATION "lib/cmake/${PROJECT_NAME}"
)