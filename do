while getopts f: flag
do
    case "${flag}" in
        f) format=true;;
    esac
done

if $format ; then
    # Script to run clang formatting on all code contained
    find -iname *.h -o -iname *.cpp | xargs -d '\n' clang-format -i
fi