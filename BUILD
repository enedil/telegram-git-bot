"""
cmake_external(
        name = "libseastar",
        deps = ["@seastar"],
        cmake_options = ["-GNinja"],
        generate_crosstool_file = True,
        lib_source = "seastar_srcs",
        make_commands = ["ninja","ninja install"],
        visibility = ["//visibility:public"]
)
"""
cc_library(
        name = "main",
        deps = ["@seastar"],
        srcs = ["main.cc"]
)
