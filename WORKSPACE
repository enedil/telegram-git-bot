load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

new_git_repository(
        name = "seastar", 
        remote = "https://github.com/scylladb/seastar/", 
        build_file = "seastar.BUILD",
        #workspace_file = "seastar.WORKSPACE",
        commit = "5a68003f0385d9dc3d25d50ffb7a9a50cf7c2206", 
        shallow_since = "1589815181 +0200",
)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
   name = "rules_foreign_cc",
   strip_prefix = "rules_foreign_cc-main",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/main.zip",
)

load("@rules_foreign_cc//:workspace_definitions.bzl", "rules_foreign_cc_dependencies")
#rules_foreign_cc_dependencies([
#    "@rules_foreign_cc//tools/build_defs:cmake_toolchain",
#    "@rules_foreign_cc//tools/build_defs:ninja_toolchain"
#])
rules_foreign_cc_dependencies()
