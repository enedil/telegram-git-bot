load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

filegroup(
        name = "seastar_srcs",
        srcs = [
                "**/*.cc",
                "**/*.hh",
        ],
        visibility = ["//visibility:public"]
)

cmake_external(
    name = "seastar",
    # expect to find ./lib/hello.lib as the result of the build
    #lib_name = "hello",
    # explicitly specify the generator
    cmake_options = ["-GNinja"],
    generate_crosstool_file = True,
    lib_source = ":srcs",
    # specify to call ninja after configuring
    make_commands = [
        "ninja",
        "ninja install",
    ],
)
