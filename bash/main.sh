#!/usr/bin/env bash

set -o verbose # set -v
set -o xtrace  # set -x
set -o posix
set -o nounset # set -u
set -o errexit # set -e
trap 'echo "Aborting due to errexit on line $LINENO. Exit code: $?" >&2' ERR
set -o errtrace # set -E
set -o pipefail

# set -o noexec # set -n

_main() {
    printf "Hello, World!\\n"
}

_main "$@"

exit 0
