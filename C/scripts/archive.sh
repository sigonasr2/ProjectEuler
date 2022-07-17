#Archives the current project under the applicable program name.
#C
if [[ "$#" -gt 1 ]];
then
    mkdir archives/$1
    cp -R src current archives/$1
    ./sig commit "${*:2}"
    cat template > src/main.c
else
    echo "Usage: "
    echo "  ./sig archive <problem> <commit msg>"
fi