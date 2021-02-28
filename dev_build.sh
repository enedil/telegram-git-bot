#!/bin/sh
set -e

repo_root="$(dirname "$(realpath $0)")"

echo $repo_root

cd $repo_root
./prepare.sh
mkdir -p build
./scripts/build.sh $repo_root
