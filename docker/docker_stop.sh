containerid=$(docker ps  -qf "ancestor=bawkbak/docker-moosrosbridge:01")
docker stop $containerid
echo "stop $containerid"
