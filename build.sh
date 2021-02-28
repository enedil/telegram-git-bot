#!/bin/sh

repo_root="$(dirname "$(realpath $0)")"

cd $repo_root
./prepare.sh
docker build -t tel_git_bot_builder .
docker run --volume "$repo_root:/sourcetree:Z" \
        tel_git_bot_builder
