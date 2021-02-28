load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

filegroup(
        name = "seastar_srcs",
        srcs = glob(["**"]),
        #visibility = ["//visibility:public"]
)

cmake_external(
    name = "seastar",
    cache_entries = {
            "CMAKE_BUILD_TYPE": "RelWithDebInfo",
            "CMAKE_C_COMPILER": "gcc",
            "CMAKE_CXX_COMPILER": "/home/enedil/comp",
    },
    cmake_options = [
            "-GNinja",
            "-DSeastar_API_LEVEL=6",
            "-DSeastar_EXCLUDE_TESTS_FROM_ALL=yes",
            "-DSeastar_EXCLUDE_APPS_FROM_ALL=yes",
            "-DSeastar_EXCLUDE_DEMOS_FROM_ALL=yes",
            "-DSeastar_CXX_FLAGS=",
            "-DSeastar_LD_FLAGS=",
            "-DSeastar_CXX_DIALECT=gnu++17",
            "-DSeastar_DPDK=no",
            "-DSeastar_DPDK_MACHINE=native",
            "-DSeastar_HWLOC=yes",
            "-DSeastar_ALLOC_FAILURE_INJECTION=DEFAULT",
            "-DSeastar_TASK_BACKTRACE=no",
            "-DSeastar_ALLOC_PAGE_SIZE=no",
            "-DSeastar_SPLIT_DWARF=no",
            "-DSeastar_HEAP_PROFILING=no",
            "-DSeastar_UNUSED_RESULT_ERROR=no"
    ],
    generate_crosstool_file = True,
    lib_source = ":seastar_srcs",
    # specify to call ninja after configuring
    make_commands = [
        "ninja",
        "ninja install"
    ],
    visibility = ["//visibility:public"],
    data = [":seastar_srcs"]
)
