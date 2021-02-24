load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
   name = "rules_foreign_cc",
   strip_prefix = "rules_foreign_cc-main",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/main.zip",
)
load("@rules_foreign_cc//:workspace_definitions.bzl", "rules_foreign_cc_dependencies")
rules_foreign_cc_dependencies([], False)

