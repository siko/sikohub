from netdisco.discovery import NetworkDiscovery

netdis = NetworkDiscovery()

netdis.scan()

for dev in netdis.discover():
    print(dev, netdis.get_info(dev))

netdis.stop()


