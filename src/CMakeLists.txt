file(GLOB Sources "*.cpp")

# Sources #

set(MY_HEADER_FILES
  ${MY_HEADER_FILES}
  GraphicsManager.hpp
  Color.hpp
  Mesh.hpp
)

set(MY_SOURCE_FILES
  ${MY_SOURCE_FILES}
  main.cpp
  GraphicsManager.cpp
  Mesh.cpp
)

add_executable(GLTutorial
  ${MY_HEADER_FILES}
  ${MY_SOURCE_FILES}
)

target_link_libraries(GLTutorial glfw)
target_link_libraries(GLTutorial ${OPENGL_gl_LIBRARY} glfw glm)