add_executable(tasking
        tasking.c
)

target_link_libraries(tasking pico_stdlib freertos)
pico_add_extra_outputs(tasking)
