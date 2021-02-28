#!/bin/sh
set -e

repo_root="$(dirname "$(realpath $0)")"

if command -v docker &> /dev/null; then
    DOCKER=docker
elif command -v podman &> /dev/null; then
    DOCKER=podman
else
    echo "Install docker or something idk"
    exit -1
fi

cd $repo_root
./prepare.sh
$DOCKER build -t tel_git_bot_builder .
$DOCKER run --volume "$repo_root:/sourcetree:Z" \
        tel_git_bot_builder
