import matplotlib.pyplot as plt

def plot_tree(ax, n, x, y, dx):
   ax.text(x, y, str(n), ha='center', va='center', fontsize=12, 
            bbox=dict(boxstyle='round,pad=0.3', edgecolor='black', facecolor='white'))
   if  n == 0 or n==1:
      return
	for i in range(2):
		plot_tree(ax, n - 1, x - dx, y - 1, dx / 8)
		ax.plot([x, x - dx], [y, y - 1], 'k-')  


   for i in range(15):
      new_x = x + (i+1)* dx
      new_y = y - 1
      plot_tree(ax, n - 2, new_x, new_y, dx / 14)
      ax.plot([x, new_x], [y, new_y], 'k-')  


fig, ax = plt.subplots(figsize=(300, 100))
ax.axis('off')


plot_tree(ax, 3, 0, 0, 24) #n=3 после поменять на 4
plt.savefig('tree.png', format='png')
