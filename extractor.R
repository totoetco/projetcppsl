library(plotly)
a = read.table("output.txt", dec = ".", header = TRUE,sep = ",")
col1 = a$t_value
col2 = a$A_init
col3 = a$ratiocellfinal
col1.sorted <- col1[order(col1)]
col2.sorted <- col2[order(col1)]
col3.sorted <- col3[order(col1)]
m <- matrix(nrow = length(unique(col1.sorted)), ncol = length(unique(col2.sorted)))
dimnames(m) <- list(unique(col1.sorted), unique(col2.sorted))
lengthtot <- 1
for(i in 1:length(unique(col1.sorted))){ # de 1 à 2
  for(j in 1:length(unique(col2.sorted))){ # de 1 à 4
    m[i,j] = col3.sorted[lengthtot]
    lengthtot <- lengthtot+1
  }
}
colfunc <- colorRampPalette(c("green","yellow","orange","red"))
plot(rep(1,15),col=colfunc(15),pch=19,cex=3)
heatmap(m,Rowv = NA, Colv = NA,main = "Magnifique Plot",col = colfunc(15))
