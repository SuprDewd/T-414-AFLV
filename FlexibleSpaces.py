
W , P = input().split()
W = int(W)
partitions = input().split()

room_widths = set({W})
for partition in range(len(partitions)):
    width = int(partitions[partition])
    room_widths.add(W - width)
    room_widths.add(width)
    for other_partition in range(partition + 1, len(partitions)):
        width2 = int(partitions[other_partition])
        room_widths.add(width2-width)
room_sizes = list(room_widths)
room_sizes.sort()
for room in room_sizes:
    print(room, end = " ")
