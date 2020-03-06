cc_binary(
    name = "tests",
    srcs = ["tests.cc"],
    linkopts = [
        "-l gradescope_test_listener",
        "-l gtest",
        "-l pthread",
    ],
    deps = [
        "//submission",
        #"@stargrade//stargrade/gtest:gradescope_test_listener",
    ],
)
