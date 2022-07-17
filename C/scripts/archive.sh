#Archives the current project under the applicable program name.
#C
if [[ "$#" -eq 2 ]];
then
    mkdir archives/$1
    cp -R src current archives/$1
    ./sig commit "${*:2}"
else
    echo "Usage: "
    echo "  ./sig archive <problem> <commit msg>"
fi