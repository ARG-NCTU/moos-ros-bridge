containerid=$(docker ps  -qf "ancestor=debug:01")
docker stop $containerid
echo "stop $containerid"
