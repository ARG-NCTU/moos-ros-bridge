containerid=$(docker ps  -qf "ancestor=hsuchaochun/moosrosbridge:u18")
docker stop $containerid
echo "stop $containerid"
