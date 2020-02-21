prompt = {'Digite o eixo X1','Digite o eixo X2','Digite o eixo Y1','Digite o eixo Y2'};
dlgtitle = 'Input';
dims = [1 35];
definput = {'0','0','0','0'};
answer = inputdlg(prompt,dlgtitle,dims,definput);

plot([str2num(answer{1}),str2num(answer{2})],[str2num(answer{3}),str2num(answer{4})],'.-r');
