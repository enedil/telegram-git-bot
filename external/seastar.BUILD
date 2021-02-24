filegroup(
    name = "seastar_sources",
    srcs = glob([
        "testdata/*.dat",
        "testdata/logs/**/*.log",
    ]),
)

genrule(
    name = "logo_miniature",
    srcs = ["logo.png"],
    outs = ["small_logo.png"],
    cmd = "convert $< -resize 100x100 $@",
)

cc_binary(
    name = "my_app",
    srcs = ["my_app.cc"],
    data = [":logo_miniature"],
)


cc_binary(
    name = "seastar",
    visibility = ["//visibility:public"],
)
