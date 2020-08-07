/*	几乎每一个函数都有其对应的 浮点版本, 也有一个与 x,y,width,height 对应的 rect 版本
	GDI版本,四个参数 x,y,width,height 通常为 x1,y1,x2,y2
*/
Status DrawArc(
const Pen *pen,
INT x,
INT y,
INT width,
INT height,
REAL startAngle,	//以 x 轴,逆时针方向旋转的角度
REAL sweepAngle);	//扫过的夹角

Status DrawPolygon(
const Pen *pen,
const Point *points,
INT *count
);

/*
若p1和p2点的y值相等,则为水平方向的渐变;
若p1和p2点的x值相等,则为垂直方向的渐变;
p1和p2点的x和y值都不相等,则为斜对角方向的渐变
为了实现过度,最好调用 Brush::SetWrapMode(WrapModeTileFlipX);
还存在其他的构造函数,如依据一个矩形而不是两个点来渐变;或者旋转一个角度
*/
LinearGradientBrush(p1, p2, col1, col2);