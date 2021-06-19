# CMakeList.txt: проект CMake для mario; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (mario "mario.cpp")
target_link_libraries(mario PUBLIC sfml-graphics sfml-window sfml-system)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/pichi/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/pichi/)
add_executable ( mariotests "mariotests.cpp" )
target_link_libraries(mariotests PUBLIC sfml-graphics sfml-window sfml-system doctest::doctest default)
doctest_discover_tests(mariotests)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
