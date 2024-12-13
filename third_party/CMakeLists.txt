set(third_party_include_dir
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
        ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include
        ${CMAKE_CURRENT_SOURCE_DIR}/assimp/include

        PARENT_SCOPE)

set(third_party_src_dir
        ${CMAKE_CURRENT_SOURCE_DIR}/imgui
        ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends
        ${CMAKE_CURRENT_SOURCE_DIR}/stbi
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/src

        PARENT_SCOPE)

set(third_party_link_dir
        ${CMAKE_CURRENT_SOURCE_DIR}/glfw/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/assimp/lib

        PARENT_SCOPE)

set(third_party_link_libs
        assimp
        glfw

        PARENT_SCOPE)