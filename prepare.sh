#!/bin/sh

repo_root="$(dirname "$(realpath $0)")"

function get_repo_dir() {
    echo "$(basename -s .git "$1")"
}


function clone_external_deps() {
    mkdir -p $repo_root/external/
    cd $repo_root/external/
    SEASTAR_REPO="https://github.com/scylladb/seastar.git"
    _repo_dir="$(get_repo_dir $SEASTAR_REPO)"
    if ! [ -d "$_repo_dir" ]; then
        git clone "$SEASTAR_REPO"
    fi
    cd "$_repo_dir"
    git fetch --tag origin "seastar-20.05.0"
    git checkout "tags/seastar-20.05.0"
}

clone_external_deps
